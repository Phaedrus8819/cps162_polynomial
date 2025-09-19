#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

class Polynomial{
    public:
        // Constructor
        Polynomial(){
            head = nullptr;
        }

        // Destructor
        ~Polynomial();

        struct Term{
            int coeff; // Coefficient of the term
            int exp;   // Exponent of the term
        };

        void insertTerm(Term &term);
        void display() const;
        static void printSum(const Polynomial &a, const Polynomial &b);
        static void printDiff(const Polynomial &a, const Polynomial &b);
        static void multPoly(const Polynomial &a, int, int);
    
    private:
        struct ListNode{
            Term value; // The value in this node
            ListNode *next; // To point to the next node
        };
        ListNode *head; // Pointer to the first node

    
};

#endif