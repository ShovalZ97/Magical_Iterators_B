#pragma once
#include <set>
#include <vector>
#include <stdexcept>
#include <iostream>
using namespace std;

namespace ariel
{
    class MagicalContainer
    {
    private:
        std::vector<int> elements;
        std::vector<int *> primeElements;
        static bool isPrime(int number);

    public:
        // Construct a new Magical Container object.
        MagicalContainer() {}
        // Destructor
        ~MagicalContainer();
        // Add an element to the container.
        // If the element already exists in the container, it will not be added.
        // Copy constructor
        MagicalContainer(const MagicalContainer &other)=default;
        // Move constructor
        MagicalContainer(MagicalContainer &&other) noexcept = default;
        // Copy assignment operator
        MagicalContainer &operator=(const MagicalContainer &other);
        // Move assignment operator.
        MagicalContainer &operator=(MagicalContainer &&other) noexcept = default;
        void addElement(int element);
        // Remove an element from the container
        // element - the element to remove
        // OutLine
        void removeElement(int element);
        // return The size of the container.
        static bool sort1(const int *aa1, const int *bb1);
        // InLine
        size_t size() const
        {
            return elements.size();
        }
        // An iterator that iterates over the container's elements in ascending order.
        class AscendingIterator
        {
        private:
            MagicalContainer *container1;
            size_t ind = 0;
            // std::vector<int>::iterator itAscending;

        public:
            // Constructor
            AscendingIterator(MagicalContainer &cont)
                : container1(&cont), ind(0) {}
            // Destructor
            ~AscendingIterator() = default;
            // Copy constructor
            AscendingIterator(const AscendingIterator &other);
            // Move constructor
            AscendingIterator(AscendingIterator &&other) noexcept = default;
            // Copy assignment operator
            AscendingIterator &operator=(const AscendingIterator &other);
            // Move assignment operator.
            AscendingIterator &operator=(AscendingIterator &&other) noexcept = default;
            // Checks if this iterator is less than the other iterator
            bool operator<(const AscendingIterator &other) const;
            // Checks if this iterator is greater than the other iterator
            bool operator>(const AscendingIterator &other) const;
            // Checks if two iterators are equal
            bool operator==(const AscendingIterator &other) const;
            // Checks if two iterators are not equal
            bool operator!=(const AscendingIterator &other) const;
            // Returns the element at the current index
            int operator*() const;
            // Increments the iterator to the next element
            AscendingIterator &operator++()
            {
                if (ind >= container1->size())
                {
                    throw std::runtime_error("Out of container");
                }
                ind++;
                return *this;
            }
            // Returns an iterator to the first element in the container.
            AscendingIterator begin()
            {
                return AscendingIterator(*container1);
            }
            // Returns an iterator to the element after the last element in the container.
            AscendingIterator end() const
            {
                AscendingIterator iter1(*container1);
                iter1.ind = container1->size();
                return iter1;
            }
        };
        // A class representing an iterator over the elements of the container in sidecross order.
        class SideCrossIterator
        {
        private:
            MagicalContainer *container1;
            size_t ind = 0;
            // std::vector<int>::iterator start1;
            // std::vector<int>::iterator end1;
            // std::vector<int>::iterator itSideStart;
            // std::vector<int>::iterator itSideEnd;

        public:
            // Constructor
            SideCrossIterator(MagicalContainer &cont)
                : container1(&cont), ind(0) {}
            // Destructor
            ~SideCrossIterator() = default;
            // Copy constructor
            SideCrossIterator(const SideCrossIterator &other) = default;
            // Move constructor
            SideCrossIterator(SideCrossIterator &&other) noexcept = default;
            // Copy assignment operator
            SideCrossIterator &operator=(const SideCrossIterator &other);
            // Move assignment operator
            SideCrossIterator &operator=(SideCrossIterator &&other) noexcept = default;
            // Checks if two iterators are equal
            bool operator==(const SideCrossIterator &other) const;
            // Checks if two iterators are not equal
            bool operator!=(const SideCrossIterator &other) const;
            // Checks if this iterator is less than the other iterator
            bool operator<(const SideCrossIterator &other) const;
            // Checks if this iterator is greater than the other
            bool operator>(const SideCrossIterator &other) const;
            // Returns the element at the current index
            int operator*() const;
            // Increments the iterator to the next element.
            SideCrossIterator &operator++()
            {
                if (ind >= container1->size())
                {
                    throw std::runtime_error("Out of container");
                }
                ind++;
                return *this;
            }
            // Returns an iterator to the first element in the container
            SideCrossIterator begin()
            {
                return SideCrossIterator(*container1);
            }
            // Returns an iterator to the element after the last element in the container
            SideCrossIterator end() const
            {
                SideCrossIterator iter1(*container1);
                iter1.ind = container1->size();
                return iter1;
            }
        };

        class PrimeIterator
        {
        private:
            MagicalContainer *container1;
            size_t ind;

        public:
            // Constructor
            PrimeIterator(MagicalContainer &container) : container1(&container), ind(0) {}
            // Destructor
            ~PrimeIterator() = default;
            // Copy constructor
            PrimeIterator(const PrimeIterator &other);
            // Move constructor
            PrimeIterator(PrimeIterator &&other) noexcept = default;
            // Copy assignment operator
            PrimeIterator &operator=(const PrimeIterator &other)
            {
                if (this != &other)
                {
                    if (&container1 != &other.container1)
                    {
                        throw std::runtime_error("Different containers");
                    }
                    ind = other.ind;
                }
                return *this;
            }
            // Move assignment operator
            PrimeIterator &operator=(PrimeIterator &&other) noexcept
            {
                if (this != &other)
                {
                    container1 = other.container1;
                    ind = other.ind;
                }
                return *this;
            }

            // Checks if this iterator is less than the other iterator
            bool operator<(const PrimeIterator &other) const;
            // Checks if this iterator is greater than the other iterator
            bool operator>(const PrimeIterator &other) const;
            // Checks if two iterators are equal
            bool operator==(const PrimeIterator &other) const;
            // Checks if two iterators are not equal
            bool operator!=(const PrimeIterator &other) const;
            // Returns the element at the current index
            int operator*() const;
            // Increments the iterator to the next element
            PrimeIterator &operator++()
            {
                if (ind >= container1->primeElements.size())
                {
                    throw std::runtime_error("Out of container");
                }
                ind++;
                return *this;
            }
            // Returns an iterator to the first element in the container
            PrimeIterator begin()
            {
                return PrimeIterator(*container1);
            }
            // Returns an iterator to the element after the last element in the container.
            PrimeIterator end() const
            {
                PrimeIterator iter1(*container1);
                iter1.ind = container1->primeElements.size();
                return iter1;
            }
        };
    };
}