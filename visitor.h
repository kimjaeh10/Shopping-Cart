#ifndef VISITOR_H
#define VISITOR_H

class ShoppingCart;

class Visitor
{
public:
    Visitor(){}
    virtual ~Visitor(){}

    virtual void visitShoppingCart(ShoppingCart*) = 0; // Shopping cart visitor.
};

#endif // VISITOR_H
