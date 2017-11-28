#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>

#include "Account.h"

void switch_validate(int& choice);

void create_account(std::string name, std::string password);

Account read_account(Account& a);
std::vector<Account> get_users();
