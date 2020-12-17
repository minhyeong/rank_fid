/*
    参照元
    https://takeda25.hatenablog.jp/entry/20140201/1391250137
*/

#ifndef Rank_hpp
#define Rank_hpp

#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <vector>

#define FILE_PATH "../dataset/single_array.txt"

class Rank {
   private:
    std::vector<bool> bits_;
    std::vector<int> f_rank_;
    std::vector<int> s_rank_;

   public:
    Rank() {
        std::random_device rnd;
        std::ifstream ifs(FILE_PATH);

        if (ifs.fail()) {
            std::cerr << "ERROR : Failed File Open" << std::endl;
            exit(-1);
        } else {
            std::cout << "Reading for [" << FILE_PATH << "]" << std::endl;
        }
        for (std::string s; getline(ifs, s);) {
            if (not s.empty()) {
                if (s == "0")
                    bits_.push_back(false);
                else
                    bits_.push_back(true);
            }
        }

        //**************************************************************

        f_rank();
        s_rank();
    }

    void f_rank() {
        // 256ごとの大ブロックの１の数
        f_rank_.push_back(0);
        for (int i = 0; i < (bits_.size() / 256) + 1; i++) {
            f_rank_.push_back(sum_1((i + 1) * 256 - 1));
        }
        int i = 0;
        /*for (auto v : f_rank_) {
            std::cout << (i * 256) << " : " << (i + 1) * 256 - 1 << " : " << v
                      << std::endl;
            i++;
        }*/
    }

    void s_rank() {
        // 8ごとの小ブロックの１の数
        s_rank_;
        //
    }

    int sum_1(int max_) {
        if (max_ > bits_.size()) max_ = bits_.size();
        int sum = 0;
        for (int i = 0; i <= max_; i++) {
            if (bits_[i] == 1) sum++;
        }
        return sum;
    }

    void print() {
        int i = 0;
        for (auto v : bits_) {
            std::cout << ++i << " : " << v << std::endl;
        }
    }
};

#endif /* Rank_hpp */