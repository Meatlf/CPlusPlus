#include <iostream>
#include <vector>

// 说明：本例主要目的是理解关于std::vector<类名 *>的语法

class ECB
{
private:
    int count_;
    int dataCodewords_;

public:
    ECB(int count, int dataCodewords);
    int getCount();
    int getDataCodewords();
};

class ECBlocks
{
private:
    int ecCodewords_;

    std::vector<ECB *> ecBlocks_;

public:
    ECBlocks(int ecCodewords, ECB *ecBlocks);
    ECBlocks(int ecCodewords, ECB *ecBlocks1, ECB *ecBlocks2);
    int getECCodewords();
    std::vector<ECB *> &getECBlocks();
    ~ECBlocks();
};

ECB::ECB(int count, int dataCodewords) : count_(count), dataCodewords_(dataCodewords)
{
}

int ECB::getCount()
{
    return count_;
}

int ECB::getDataCodewords()
{
    return dataCodewords_;
}

ECBlocks::ECBlocks(int ecCodewords, ECB *ecBlocks) : ecCodewords_(ecCodewords), ecBlocks_(1, ecBlocks)
{
}

ECBlocks::ECBlocks(int ecCodewords, ECB *ecBlocks1, ECB *ecBlocks2) : ecCodewords_(ecCodewords), ecBlocks_(1, ecBlocks1)
{
    ecBlocks_.push_back(ecBlocks2);
}

int ECBlocks::getECCodewords()
{
    return ecCodewords_;
}

std::vector<ECB *> &ECBlocks::getECBlocks()
{
    return ecBlocks_;
}

ECBlocks::~ECBlocks()
{
    // for (size_t i = 0; i < ecBlocks_.size(); i++)
    // {
    //     delete ecBlocks_[i];
    // }
}

int main()
{
    int ecCodewords = 50;
    ECB ecb1(2, 6);
    ECB ecb2(3, 7);
    std::vector<ECB *> vpecb(2);
    vpecb[0] = &ecb1;
    vpecb[1] = &ecb2;
    ECB *pecb = vpecb[0];
    ECBlocks ecBlocks(5, pecb);
    std::cout << ecBlocks.getECCodewords() << std::endl;
    std::vector<ECB *> vpECB = ecBlocks.getECBlocks();
    std::cout << vpECB[0]->getCount();
    std::cout << vpECB[0]->getDataCodewords() << std::endl;
    return 0;
}
