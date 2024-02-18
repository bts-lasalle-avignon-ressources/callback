#include <iostream>
#include <functional>

class FooAbstractListener
{
    public:
        virtual void onEvent() = 0;
        virtual void onError() = 0;
};

class Foo
{
    public:
        Foo();
        ~Foo();
        void traiter();
        void setCallback(FooAbstractListener *callback);

    private:
        FooAbstractListener *callback; // Pour les fonctions de rappel sur évènement (onEvent, onError, ...)
    
};

Foo::Foo() : callback(nullptr)
{
}

Foo::~Foo()
{
}

void Foo::traiter()
{
    // Effectue le traitement et
    // SI condition ALORS on déclenche le rappel ...
    if(callback != nullptr)
    {
        callback->onEvent();
    }
}

void Foo::setCallback(FooAbstractListener *callback)
{
    this->callback = callback;
}

class FooListener : public FooAbstractListener
{
    public:
        void onEvent();
        void onError();
};

// La méthode de rappel déclenchée sur évènement
void FooListener::onEvent()
{
    // ...
    std::cout << __FUNCTION__ << std::endl;
}

// La méthode de rappel déclenchée sur l'évènement erreur
void FooListener::onError()
{
    // ...
    std::cout << __FUNCTION__ << std::endl;
}

int main()
{
    // Instancie un objet
    Foo foo;

    // Installe les fonctions de rappel
    foo.setCallback(new FooListener());

    // Réalise un traitement
    foo.traiter();

    return 0;
}
