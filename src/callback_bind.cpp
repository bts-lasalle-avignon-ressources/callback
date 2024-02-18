#include <iostream>
#include <functional>

class Foo
{
  public:
    Foo();
    ~Foo();

    void traiter();
    void setCallback( std::function<void()> f );
    void onEvent();

  private:
    std::function<void()> _callback;
};

Foo::Foo() : _callback(nullptr)
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

void Foo::setCallback( std::function<void()> f )
{
    _callback = f;
}

// L'évènement Event déclenchera l'appel à callback
void Foo::onEvent()
{
    if ( _callback != nullptr)
    {
        _callback();
    }
}

class Bar
{
    public:
        Bar() { }
        void methodeRappel();
};


// La méthode de rappel
void Bar::methodeRappel()
{
    // ...
    std::cout << __FUNCTION__ << std::endl;
}

int main()
{
    // Instancie un objet
    Foo foo;
    //Bar bar;

    // Installe le rappel
    //foo.setCallback(std::bind(&Bar::methodeRappel, &bar));
    foo.setCallback(std::bind(&Bar::methodeRappel, new Bar()));

    // Réalise un traitement
    foo.traiter();

    return 0;
}
