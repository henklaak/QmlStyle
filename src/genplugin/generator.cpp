#include <lsbutton.h>
#include <lscheckbox.h>
#include <lsradiobutton.h>
#include <lsprogressbar.h>
#include <lsslider.h>
#include <lssliderindicator.h>
#include <lstextfield.h>
#include <lscombobox.h>
#include <lsprogressbarindicator.h>

int main( int a_argc, char *a_argv[] )
{
    {
        LsProgressBarIndicator renderer;
        renderer.render();
    }
    {
        LsSliderIndicator renderer;
        renderer.render();
    }
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
    {
        LsTextField renderer;
        renderer.render();
    }
    {
        LsComboBox renderer;
        renderer.render();
    }
    return 0;
}
