#include "Instance.hpp"

UImGuiDemo::Instance::Instance()
{
    initInfo =
    {
        .inlineComponents = { (UImGui::InlineComponent*)&demoWindow },
        UIMGUI_INIT_INFO_DEFAULT_DIRS,
    };
}

void UImGuiDemo::Instance::begin()
{
    beginAutohandle();

}

void UImGuiDemo::Instance::tick(float deltaTime)
{
    tickAutohandle(deltaTime);

}

void UImGuiDemo::Instance::end()
{
    endAutohandle();

}

UImGuiDemo::Instance::~Instance()
{

}

void UImGuiDemo::Instance::onEventConfigureStyle(ImGuiStyle& style, ImGuiIO& io)
{

}