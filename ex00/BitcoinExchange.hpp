/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 22:33:08 by hlabouit          #+#    #+#             */
/*   Updated: 2024/03/05 23:21:33 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_H
# define BITCOINEXCHANGE_H

#include<fstream>
#include<iostream>
#include<string>
#include<iomanip>
#include<ctype.h>
#include<cstdlib>
#include<cmath>
#include<sstream>
#include<algorithm>
#include<iterator>
#include<vector>
#include<map>
 
class BitcoinExchange {
    private:
        std::map<std::string, double> Mcontainer_data;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &primary);
        BitcoinExchange &operator=(const BitcoinExchange &primary);
        void parsing(std::string date);
        void insert_key_val_in_MC();
        void read_input_file(std::string input_file);
        double to_number(std::string str);
        void display_BTCexchange();
        ~BitcoinExchange();
};

#endif
