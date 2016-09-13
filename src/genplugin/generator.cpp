#include <lsbutton.h>
#include <lscheckbox.h>
#include <lsradiobutton.h>
#include <lsprogressbar.h>
#include <lsslider.h>
#include <lssliderindicator.h>
#include <lstextfield.h>
#include <lscombobox.h>
#include <lsprogressbarindicator.h>
#include <lstoolbutton.h>
#include <lstoolbuttonleft.h>
#include <lstoolbuttonright.h>
#include <lstoolbuttonboth.h>

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
        LsProgressBarIndicator renderer;
        renderer.render();
    }
    {
        LsSlider renderer;
        renderer.render();
    }
    {
        LsSliderIndicator renderer;
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
    {
        LsToolButtonBoth renderer;
        renderer.render();
    }
    {
        LsToolButtonLeft renderer;
        renderer.render();
    }
    {
        LsToolButtonRight renderer;
        renderer.render();
    }
    {
        LsToolButton renderer;
        renderer.render();
    }

    return 0;
}
