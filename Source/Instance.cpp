#include "Instance.hpp"

UImGuiDemo::Instance::Instance() noexcept
{
    initInfo =
    {
        .windowComponents = { reinterpret_cast<UImGui::WindowComponent*>(&demoWindow) },
        UIMGUI_INIT_INFO_DEFAULT_DIRS,
    };
}

void UImGuiDemo::Instance::begin() noexcept
{
    beginAutohandle();

}

void UImGuiDemo::Instance::tick(const float deltaTime) noexcept
{
    tickAutohandle(deltaTime);

}

void UImGuiDemo::Instance::end() noexcept
{
    endAutohandle();

}

void UImGuiDemo::Instance::onEventConfigureStyle(ImGuiStyle& style, ImGuiIO& io) noexcept
{

}