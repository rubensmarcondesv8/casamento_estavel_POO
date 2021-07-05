#ifndef LOCALIZACAO_H
#define LOCALIZACAO_H

class Localizacao
{
    public:

    Localizacao(double xx = 0, double yy = 0) : x(xx), y(yy) {};

    double getX() const { return x; }

    double getY() const { return y; }

    private:
        double x;
        double y;
    
};

#endif