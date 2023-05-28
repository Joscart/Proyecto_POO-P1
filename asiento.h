#ifndef ASIENTO_H
#define ASIENTO_H


class Asiento
{
private:
    int posFila;
    int posColumna;
    bool ocupancia = false;
public:
    Asiento();
    ~Asiento();
    int getPosFila() const;
    void setPosFila(int newPosFila);
    int getPosColumna() const;
    void setPosColumna(int newPosColumna);
    bool getOcupancia() const;
    void setOcupancia(bool newOcupancia);
};

#endif // ASIENTO_H
