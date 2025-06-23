#include "Title.hpp"

UImGuiDemo::Title::Title()
{

}

void UImGuiDemo::Title::begin()
{
    beginAutohandle();

    builder
#ifdef __APPLE__
    .addSubmenu("", UImGui::TitlebarBuilder{}
        .addAppMenuDefaultItems()
    )
    .addSubmenu("Window", UImGui::TitlebarBuilder{}
        .addWindowMenuDefaultItems()
    )
    .addSubmenu("Help", UImGui::TitlebarBuilder{}
        .addHelpMenuDefaultItems()
    )
#endif
    .setBuildNativeOnMacOS(true).finish();
}

void UImGuiDemo::Title::tick(const float deltaTime)
{
    tickAutohandle(deltaTime);
}

void UImGuiDemo::Title::end()
{
    endAutohandle();

}

UImGuiDemo::Title::~Title()
{

}