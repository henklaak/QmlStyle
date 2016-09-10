#include <lsbutton.h>
#include <lscheckbox.h>
#include <lsradiobutton.h>
#include <lsprogressbar.h>

int main( int a_argc, char *a_argv[] )
{
    {
        LsButton renderer;
        renderer.render();
    }
    {
        LsCheckBox renderer;
        renderer.render();
    }

    {
        LsRadioButton renderer;
        renderer.render();
    }
    {
        LsProgressBar renderer;
        renderer.render();
    }
    return 0;
}
