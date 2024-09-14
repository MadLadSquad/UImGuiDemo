#include "DemoWindow.hpp"

UImGuiDemo::DemoWindow::DemoWindow()
{

}

void UImGuiDemo::DemoWindow::begin()
{
    beginAutohandle();
    const auto& io = ImGui::GetIO();

    io.Fonts->AddFontDefault();
    static UImGui::TextUtilsData data =
    {
        .bold = io.Fonts->AddFontFromFileTTF(UIMGUI_CONTENT_DIR"Ubuntu-Bold.ttf", 16.0f),
        .italic = io.Fonts->AddFontFromFileTTF(UIMGUI_CONTENT_DIR"Ubuntu-Italic.ttf", 16.0f),
        .boldItalic = io.Fonts->AddFontFromFileTTF(UIMGUI_CONTENT_DIR"Ubuntu-BoldItalic.ttf", 16.0f),
        .monospace = io.Fonts->AddFontFromFileTTF(UIMGUI_CONTENT_DIR"JetBrainsMono-Regular.ttf", 16.0f),
        .smallFont = io.Fonts->AddFontFromFileTTF(UIMGUI_CONTENT_DIR"Ubuntu-Light.ttf", 13.0f),
    };
    UImGui::TextUtils::initTextUtilsData(&data);
}

void UImGuiDemo::DemoWindow::tick(const float deltaTime)
{
    tickAutohandle(deltaTime);

    ImGui::ShowDemoWindow();
    ImPlot::ShowDemoWindow();
    UImGui::TextUtils::ShowDemoWindow();

    {
        ImGui::Begin("Spinners demo");
        ImSpinner::demoSpinners();
        ImGui::End();
    }

    {
        constexpr static ImVec4 green(0.16f, 0.66f, 0.45f, 1.0f);
        constexpr static ImVec4 green_hover(0.0f, 1.0f, 0.57f, 1.0f);
        constexpr static ImVec4 gray_dim(0.45f, 0.45f, 0.45f, 1.0f);
        constexpr static ImVec4 gray(0.65f, 0.65f, 0.65f, 1.0f);
        constexpr static ImVec4 green_shadow(0.0f, 1.0f, 0.0f, 0.4f);

        static bool values[] = { true, true, true, true, true, true, true, true };
        size_t value_index = 0;

        ImGui::Begin("Toggles demo");

        ImGui::PushStyleColor(ImGuiCol_FrameBg, gray_dim);
        ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, gray);

        ImGui::Toggle("Default Toggle", &values[value_index++]);
        ImGui::Toggle("Animated Toggle", &values[value_index++], ImGuiToggleFlags_Animated);
        ImGui::Toggle("Bordered Knob", &values[value_index++], ImGuiToggleFlags_Bordered, 1.0f);

        ImGui::PushStyleColor(ImGuiCol_BorderShadow, green_shadow);
        ImGui::Toggle("Shadowed Knob", &values[value_index++], ImGuiToggleFlags_Shadowed, 1.0f);
        ImGui::Toggle("Bordered + Shadowed Knob", &values[value_index++], ImGuiToggleFlags_Bordered | ImGuiToggleFlags_Shadowed, 1.0f);
        ImGui::PopStyleColor(1);

        ImGui::PushStyleColor(ImGuiCol_Button, green);
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, green_hover);
        ImGui::Toggle("Green Toggle", &values[value_index++]);
        ImGui::PopStyleColor(2);

        ImGui::Toggle("Toggle with A11y Labels", &values[value_index++], ImGuiToggleFlags_A11y);
        ImGui::Toggle("##Toggle With Hidden Label", &values[value_index++]);

        ImGui::PopStyleColor(2);
        ImGui::End();
    }

    {
        static float values[] = { 0, 0, 0, 0, 0, 0, 0, 0 };

        ImGui::Begin("Knobs demo");

        ImGuiKnobs::Knob("Tick",        &values[static_cast<int>(log2(static_cast<double>(ImGuiKnobVariant_Tick       )))],    0.0f, 100.0f, 0, "%.3f", ImGuiKnobVariant_Tick     );
        ImGui::SameLine();
        ImGuiKnobs::Knob("Dot",         &values[static_cast<int>(log2(static_cast<double>(ImGuiKnobVariant_Dot        )))],    0.0f, 100.0f, 0, "%.3f", ImGuiKnobVariant_Dot      );
        ImGui::SameLine();
        ImGuiKnobs::Knob("Wiper",       &values[static_cast<int>(log2(static_cast<double>(ImGuiKnobVariant_Wiper      )))],    0.0f, 100.0f, 0, "%.3f", ImGuiKnobVariant_Wiper    );
        ImGui::SameLine();
        ImGuiKnobs::Knob("WiperOnly",   &values[static_cast<int>(log2(static_cast<double>(ImGuiKnobVariant_WiperOnly  )))],    0.0f, 100.0f, 0, "%.3f", ImGuiKnobVariant_WiperOnly);
        ImGui::SameLine();
        ImGuiKnobs::Knob("WiperDot",    &values[static_cast<int>(log2(static_cast<double>(ImGuiKnobVariant_WiperDot   )))],    0.0f, 100.0f, 0, "%.3f", ImGuiKnobVariant_WiperDot );
        ImGui::SameLine();
        ImGuiKnobs::Knob("Stepped",     &values[static_cast<int>(log2(static_cast<double>(ImGuiKnobVariant_Stepped    )))],    0.0f, 100.0f, 0, "%.3f", ImGuiKnobVariant_Stepped  );
        ImGui::SameLine();
        ImGuiKnobs::Knob("Space",       &values[static_cast<int>(log2(static_cast<double>(ImGuiKnobVariant_Space      )))],    0.0f, 100.0f, 0, "%.3f", ImGuiKnobVariant_Space    );

        ImGui::End();
    }
}

void UImGuiDemo::DemoWindow::end()
{
    endAutohandle();

}

UImGuiDemo::DemoWindow::~DemoWindow()
{

}
