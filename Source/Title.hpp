#pragma once
#include <Framework.hpp>
#include <Generated/Config.hpp>

namespace UImGuiDemo 
{
    class UIMGUI_PUBLIC_API Title : public UImGui::TitlebarComponent
    {
    public:
        Title();
        virtual void begin() override;
        virtual void tick(float deltaTime) override;
        virtual void end() override;
        virtual ~Title() override;
    private:
        UImGui::TitlebarBuilder builder{};
        int i = 0;
    };
}
