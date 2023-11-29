#include <iostream>
#include <cstring>
#include <vector>

typedef unsigned long long ull;

void day1(){
    std::string str;
    std::getline(std::cin, str);
    ull max, max1, max2, tmp;
    while(!str.empty()) {
        if (str == "\r"){
            if (tmp > max){
                max = tmp;
            }
            if (tmp != max && max1 < tmp){
                max1 = tmp;
            }
            if (tmp != max1 && tmp != max && max2 < tmp){
                max2 = tmp;
            }
            tmp = 0;
            std::getline(std::cin, str);
            continue;
        }
        tmp += std::stoi(str);
        std::getline(std::cin, str);
    }
    std::cout << "Top score:" << max << std::endl;
    std::cout << max1 << std::endl;
    std::cout << max2 << std::endl;
    std::cout << "Sum of top 3: " << max + max1 + max2 << std::endl;
}

void day2(){
    int me;
    int opponent;
    ull score = 0;
    ull score1 = 0;
    char *str = (char *)malloc(sizeof(char)*5+1);
    while (!feof(stdin)){
        fgets(str, 6, stdin);
        me = str[2] - 'X';
        opponent = str[0] - 'A';
        if (me - opponent == 0){
            score += 3;
            score += me + 1;
        }
        else if (me - opponent == -1 || me - opponent == 2){
            score += me + 1;
        }
        else{
            score += 6;
            score += me + 1;
        }
        if (me == 1){
            score1 += opponent + 1;
            score1 += 3;
        }
        else if (me == 0) {
            score1 += opponent == 0 ? 3 : opponent == 1 ? 1 : opponent == 2 ? 2 : 0;
        }
        else if (me == 2){
            score1 += 6;
            score1 += opponent == 0 ? 2 : opponent == 1 ? 3 : opponent == 2 ? 1 : 0;
        }
    }
    free(str);
    std::cout << "Part 1 score: " <<score << std::endl;
    std::cout << "Part 2 score: " << score1 << std::endl;
}

void day3(){
    ull result = 0;
    ull score = 0;
    bool found;
    std::string str[3];
    std::getline(std::cin, str[0]);
    std::getline(std::cin, str[1]);
    std::getline(std::cin, str[2]);
    while(!str[0].empty() && !str[1].empty() && !str[2].empty()){
        for (auto lol: str) {
            found = false;
            for (auto i = 0; i < lol.size() / 2; ++i) {
                for (auto j = lol.size() / 2; j < lol.size(); ++j) {
                    if (lol[i] == lol[j]){
                        found = true;
                        if (std::islower(lol[i])){ result += lol[i] - ('a' - 1); break;}
                        else {result += lol[i] - ('A' - 27); break;}
                    }
                }
                if (found){break;}
            }
        }
        found = false;
        for (auto i : str[0]){
            for (auto j : str[1]) {
                for (auto l : str[2]) {
                    if (i == j && j == l){
                        found = true;
                        if (std::islower(i)){ score += i - ('a' - 1); break;}
                        else {score += i - ('A' - 27); break;}
                    }
                }
                if (found){break;}
            }
            if (found){break;}
        }
        std::getline(std::cin, str[0]);
        std::getline(std::cin, str[1]);
        std::getline(std::cin, str[2]);
    }
    std::cout << "Part 1 score: " << result << std::endl;
    std::cout << "Part 2 score: " << score << std::endl;
}

void day4(){
    ull result = 0, score = 0;
    ull x1, x2, y1, y2;
    char *str = (char *)malloc(sizeof(char)*30);
    fgets(str, 30, stdin);
    while (!feof(stdin)){
        sscanf(str ,"%lld-%lld,%lld-%lld", &x1, &x2, &y1, &y2);
        if ((x1 >= y1 && x2 <= y2) || (x1 <= y1 && x2 >= y2)){result++; score++;}
        else if ((x1 <= y1 && x2 <= y2 && x2 >= y1) || (x1 >= y1 && x2 >= y2 && x1 <= y2) ){score++;}
        fgets(str, 30, stdin);
    }
    std::cout << "Part 1 score: " << result << std::endl;
    std::cout << "Part 2 score: " << score << std::endl;
    free(str);
}

void day5(){
    std::vector<char> stack[9];
    std::vector<char> part2_stack[9];
    stack[0] = {'N', 'B', 'D', 'T', 'V', 'G', 'Z', 'J'};
    stack[1] = {'S','R','M','D','W','P','F'};
    stack[2] = {'V','C','R','S','Z'};
    stack[3] = {'R','T','J','Z','P','H','G'};
    stack[4] = {'T', 'C', 'J', 'N', 'D', 'Z', 'Q', 'F'};
    stack[5] = {'N', 'V', 'P', 'W', 'G', 'S', 'F', 'M'};
    stack[6] = {'G', 'C', 'V', 'B', 'P', 'Q'};
    stack[7] = {'Z', 'B', 'P', 'N'};
    stack[8] = {'W', 'P', 'J'};

    part2_stack[0] = {'N', 'B', 'D', 'T', 'V', 'G', 'Z', 'J'};
    part2_stack[1] = {'S','R','M','D','W','P','F'};
    part2_stack[2] = {'V','C','R','S','Z'};
    part2_stack[3] = {'R','T','J','Z','P','H','G'};
    part2_stack[4] = {'T', 'C', 'J', 'N', 'D', 'Z', 'Q', 'F'};
    part2_stack[5] = {'N', 'V', 'P', 'W', 'G', 'S', 'F', 'M'};
    part2_stack[6] = {'G', 'C', 'V', 'B', 'P', 'Q'};
    part2_stack[7] = {'Z', 'B', 'P', 'N'};
    part2_stack[8] = {'W', 'P', 'J'};

    std::vector<char> test_stack[3];
    std::vector<char>::iterator it;
    test_stack[0] = {'Z', 'N'};
    test_stack[1] = {'M', 'C', 'D'};
    test_stack[2] = {'P'};
    int move, from, to;
    ull size, size1;
    char *str = (char *)malloc(sizeof(char) * 30);
    fgets(str, 30, stdin);
    while (!feof(stdin)){
        sscanf(str, "move %d from %d to %d", &move, &from, &to);
        size = stack[from-1].size() - move;
        for (auto i = stack[from-1].size() - 1; i >= size && i != UINT64_MAX; i--) {
            it = stack[from-1].end()-1;
            stack[to-1].push_back(stack[from-1][i]);
            stack[from-1].erase(it);
        }
        size1 = part2_stack[from-1].size();
        it = part2_stack[from-1].end() - move;
        for (auto i = part2_stack[from-1].size() - move; i < size1; i++) {
            part2_stack[to-1].push_back(part2_stack[from-1][i]);
        }
        part2_stack[from-1].erase(it, part2_stack[from-1].end());
        fgets(str, 30, stdin);
    }
    std::cout << "Part 1:";
    for (auto i : stack){
        std::cout << i[i.size()-1 != UINT64_MAX ? i.size()-1 : 0] << " ";
    }
    std::cout << std::endl;
    for (auto i : part2_stack){
        std::cout << i[i.size()-1 != UINT64_MAX ? i.size()-1 : 0] << " ";
    }
    std::cout << std::endl;
    free(str);
}

void day6(){
    ull result = 0;
    ull score = 0;
    bool got_it;
    bool got_it1;
    bool found[2] = {false, false};
    std::string str;
    std::getline(std::cin, str);
        for (auto i = 0; str[i] != '\0' && str[i] != '\n' ; ++i) {
            got_it = false;
            got_it1 = false;
            for (auto j = i; j < i + 4; ++j) {
                for (auto k = j + 1; k < i + 4; ++k) {
                    if (str[j] == str[k]){got_it = true;}
                }
            }
            for (auto j = i; j < i + 14; ++j) {
                for (auto k = j + 1; k < i + 14; ++k) {
                    if (str[j] == str[k]){got_it1 = true;}
                }
            }
            if (!got_it && !found[0]){
                found[0] = true;
                result += i + 4;
            }
            if (!got_it1 && !found[1]){
                found[1] = true;
                score += i + 14;
            }
            if(found[0] && found[1]){break;}

        }
    std::cout << "Part 1 score: " << result << std::endl;
    std::cout << "Part 2 score: " << score << std::endl;
}

int main(int argc, char **argv) {
    if (argc != 2){std::cerr << "Wrong amount of arguments!!!" << std::endl; return -1;}
    if (!std::strcmp(argv[1], "-day1")){day1();}
    if (!std::strcmp(argv[1], "-day2")){day2();}
    if (!std::strcmp(argv[1], "-day3")){day3();}
    if (!std::strcmp(argv[1], "-day4")){day4();}
    if (!std::strcmp(argv[1], "-day5")){day5();}
    if (!std::strcmp(argv[1], "-day6")){day6();}
    return 0;
}
