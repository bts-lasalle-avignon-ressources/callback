#include <iostream>

class Foo
{
  public:
    Foo();
    ~Foo();

    void traiter();
    void setCallback( void (*f)() );
    void onEvent();

  private:
    void (*_callback)();
};

Foo::Foo() : _callback(NULL)
{
}

Foo::~Foo()
{
}

void Foo::traiter()
{
    // Effectue le traitement et
    // SI condition ALORS ...
    onEvent();
}

void Foo::setCallback( void (*f)() )
{
    _callback = f;
}

// L'évènement Event déclenchera l'appel à callback
void Foo::onEvent()
{
    if ( _callback != NULL)
    {
        _callback();
    }
}

// La fonction de rappel
void fonctionRappel()
{
    // ...
    std::cout << __FUNCTION__ << std::endl;
}

int main()
{
    // Instancie un objet
    Foo foo;

    // Installe la fonction de rappel
    foo.setCallback(fonctionRappel);

    // Réalise un traitement
    foo.traiter();

    return 0;
}
