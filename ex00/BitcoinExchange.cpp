/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 22:46:59 by hlabouit          #+#    #+#             */
/*   Updated: 2024/03/03 21:21:28 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"BitcoinExchange.hpp"

void BitcoinExchange::insert_key_val_in_MC()
{
    std::string line;
    std::ifstream is("data.csv");
    
    if (!is.is_open())
    {
        std::cout<< "stream failed to open data.csv file!" << std::endl;
        exit(EXIT_FAILURE);
    }
    //inserting key-val in the map container
    std::getline(is, line); // skip first line of csv file
    while (std::getline(is, line))
    {
        std::string key = line.substr(0, 10);//!!10
        std::string value = line.substr(11);
        this->Mcontainer_data[key] = atoi(value.c_str());
    }
    is.close();
}


void BitcoinExchange::read_input_file(std::string input_file)
{
    std::string line;
    std::ifstream is(input_file);
    
    if (!is.is_open())
    {
        std::cout<< "stream failed to open input file!" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::getline(is, line);
    if (line != "date | value")
    {
        std::cout<< "invalid database file content!" << std::endl;
        exit(EXIT_FAILURE);
    }
    while (std::getline(is, line))
    {
        try
        {
            this->parsing(line);
        }
        catch(const std::exception& excp)
        {
            std::cerr << excp.what() << std::endl;
        }
    }
    is.close();
}

double BitcoinExchange::to_number(std::string str)
{
    std::stringstream ss(str);

    double mynum;
    ss >> mynum;
    if (ss.fail() || !ss.eof())
        throw std::runtime_error("string stream convertion failed!");
    return (mynum);
}

void BitcoinExchange::parsing(std::string data_base)
{
    //check date
    if (data_base.empty())
        throw std::runtime_error("stream failed to open data file!");
    if (data_base.find(" | ") == std::string::npos)
        throw std::runtime_error("data must be in this format: date | value!");
    int pos = data_base.find(" | ");
    std::string date = data_base.substr(0, pos);//throws an excp if it fails
    std::string value = data_base.substr(pos + 3);//throws an excp if it fails
    if (date.length() != 10 || value.empty() || value.find(" ") != std::string::npos)
        throw std::runtime_error("invalid date or value!");
        
    //check value
    
    std::stringstream ss(date);
    std::string YY;
    std::string MM;
    std::string DD;
    std::getline(ss, YY, '-');
    std::getline(ss, MM, '-');
    std::getline(ss, DD);

    double year = to_number(YY);
    double month = to_number(MM);
    double day = to_number(DD);
    
    if (year < 2008)
        throw std::runtime_error("invalid YEAR: 2008>>");
    if (month < 1 || month > 12)
    {
        if (month == 2 && day > 29)
            throw std::runtime_error("invalid ferbuary month: 01-29");
        throw std::runtime_error("invalid MONTH: 01-12");
    }
    if (day < 1 || day > 31)
        throw std::runtime_error("invalid DAY: 01-31");
        
    double btc_value = to_number(value);
    if (btc_value < 0 || btc_value > 1000)
        throw std::runtime_error("invalid btc value: 0-1000");


    // printf("%s | %s\n", date.c_str(), value.c_str());
    // printf("date: [%s] -------------------- value: [%s]\n", date.c_str(), value.c_str());

    std::map<std::string, int>::iterator itr =  this->Mcontainer_data.lower_bound(date);
    std::map<std::string, int>::iterator itr_begin =  this->Mcontainer_data.begin();
    if (date < itr_begin->first)
    {
        date = itr_begin->first;
        // std::cout << "data lower bound FIRST DATE: " << itr_begin->first << std::endl;
        
    }
    else if (itr->first != date)
    {   
        itr--;
        std::cout << "data lower bound NEAREST DATE: " << itr->first << std::endl;
    }
    else
    {
        std::cout << "data lower bound SAME: " << itr->first << std::endl;
    }
    
    // $> ./btc input.txt
    // 2011-01-03 => 3 = 0.9
    // 2011-01-03 => 2 = 0.6
    // 2011-01-03 => 1 = 0.3
    // 2011-01-03 => 1.2 = 0.36
    // 2011-01-09 => 1 = 0.32
    // Error: not a positive number.
    // Error: bad input => 2001-42-42
    // 2012-01-11 => 1 = 7.1
    // Error: too large a number.

}