#include "ExampleApp.h"

int main()
{
    ExampleApp app;
    if (app.wasStartOK())
    {
        app.run();
    }

    return 0;
}
