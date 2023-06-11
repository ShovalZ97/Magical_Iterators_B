#include <cstdlib>
#include <memory>
#include <algorithm>
#include <cmath>
#include "MagicalContainer.hpp"

using namespace std;
using namespace ariel;

MagicalContainer::~MagicalContainer() {}
bool MagicalContainer::isPrime(int num)
{
    if (num < 2)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(num); ++i)
    {
        if (num % i == 0)
        {
            return false;
        }
    }

    return true;
}
// add the element to the vector
void MagicalContainer::addElement(int element)
{
    elements.push_back(element);
    sort(elements.begin(), elements.end());
    // primeElements.clear();
    // for (auto iter = elements.begin(); iter != elements.end(); ++iter)
    // {

    if (isPrime(element) == true)
    {
        primeElements.push_back(new int(element));
    }
    sort(primeElements.begin(), primeElements.end(),sort1);
    //cout << "begin: " << *(*(primeElements.begin())) << endl;
    //cout << "end: " << *(*(primeElements.end())) << endl;

    // }
}
bool MagicalContainer::sort1(const int *aa1, const int *bb1)
{
    return (*aa1 < *bb1);
}
// int* MagicalContainer::sort1(int *num1, int *num2)
// {
//     if (*num1 > *num2)
//     {
//         return num1;
//     }
//     return num2;
// }
// Remove the element from vector
void MagicalContainer::removeElement(int delNum)
{
    auto iter = std::find(elements.begin(), elements.end(), delNum);
    if (iter != elements.end())
    {
        // delete the element
        elements.erase(iter);
    }
    else
    {
        throw std::runtime_error("The number is not exist");
    }
    // sort(elements.begin(), elements.end());
    // primeElements.clear();
    //  for (auto iter = elements.begin(); iter != elements.end(); ++iter)
    //  {
    //  if (isPrime(*iter))
    //  {
    //      primeElements.push_back(&(*iter));
    //  }
    // }
}
//********************Ascending Iterator *********************
int MagicalContainer::AscendingIterator::operator*() const
{

    return container1->elements[ind];
}
MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other) : container1(other.container1), ind(other.ind) {}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
{
    if (this != &other)
    {
        if (container1 != other.container1)
            throw std::runtime_error("Cannot assign iterators from different containers");

        ind = other.ind;
    }

    return *this;
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const
{
    return this->ind > other.ind;
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const
{
    return this->ind < other.ind;
}
bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const
{
    return this->ind == other.ind;
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const
{
    return this->ind != other.ind;
}
//********************Prime Iterator *********************
int MagicalContainer::PrimeIterator::operator*() const
{
    return *(container1->primeElements[ind]);
}
MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other) : container1(other.container1), ind(other.ind) {}
bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const
{
    return this->ind > other.ind;
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const
{
    return this->ind < other.ind;
}
bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
{
    return this->ind == other.ind;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
{
    return this->ind != other.ind;
}
//********************SideCross Iterator *********************
int MagicalContainer::SideCrossIterator::operator*() const
{
    size_t indRegular = 0;
    if (ind >= container1->size())
    {
        throw std::runtime_error("out of index");
    }
    if (ind % 2 == 1)
    {
        indRegular = (container1->size() - ind / 2) - 1;
    }
    else
    {
        indRegular = ind / 2;
    }
    return container1->elements[indRegular];
}
MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
{
    if (this->container1 != other.container1)
        throw std::runtime_error("The copy not succeed");
    container1 = other.container1;
    ind = other.ind;
    return *this;
}
bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
{
    if (this->container1 != other.container1)
    {
        throw std::runtime_error("Its not the same");
    }
    return ind == other.ind;
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
{
    return !(ind == other.ind);
}
bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const
{
    return ind > (other.ind);
}
bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const
{
    return (ind) < (other.ind);
}
