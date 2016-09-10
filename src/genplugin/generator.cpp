#include <lsbutton.h>
#include <lscheckbox.h>
#include <lsradiobutton.h>
#include <lsprogressbar.h>
#include <lsslider.h>

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
    {
        LsSlider renderer;
        renderer.render();
    }
    return 0;
}
