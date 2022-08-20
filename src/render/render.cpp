#include <array>
#include <cstdint>
#include <iostream>

#include "imgui.h"
#include "implot.h"

#include "render.hpp"

void render_window1()
{
    static auto toggle = false;

    ImGui::SetNextWindowPos(ImVec2{0.0F, 0.0F});
    ImGui::SetNextWindowSize(ImVec2{110.0F, 120.0F});
    const auto window_flags =
        (ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoMove |
         ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize |
         ImGuiWindowFlags_NoTitleBar);
    if (ImGui::Begin("window###1", nullptr, window_flags))
    {
        if (ImGui::Button("Click me###1", ImVec2{100.0F, 50.0F}))
        {
            toggle = !toggle;
        }

        if (toggle)
            ImGui::Text("Active");
        else
            ImGui::Text("Inactive");
    }
    ImGui::End();
}

void render_window2()
{
    ImGui::SetNextWindowPos(ImVec2{400.0F, 400.0F});
    ImGui::SetNextWindowSize(ImVec2{400.0F, 150.0F});
    const auto window_flags =
        (ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoMove |
         ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize |
         ImGuiWindowFlags_NoTitleBar);
    if (ImGui::Begin("window###2", nullptr, window_flags))
    {
        constexpr auto num_cols = 3;
        constexpr auto num_rows = 4;

        if (ImGui::BeginTable("table###1", num_cols, ImGuiTableFlags_Borders))
        {
            for (int row = 0; row < num_rows; row++)
            {
                ImGui::TableNextRow();
                ImGui::TableNextColumn();
                ImGui::Text("Row %d", row);
                ImGui::TableNextColumn();
                ImGui::PushStyleColor(ImGuiCol_Text,
                                      ImVec4{0.0F, 0.0, 1.0F, 1.0F});
                ImGui::Text("Some contents");
                ImGui::PopStyleColor();
                ImGui::TableNextColumn();
                ImGui::PushStyleColor(ImGuiCol_Text,
                                      ImVec4{1.0F, 0.0, 0.0F, 1.0F});
                ImGui::Text("123.456");
                ImGui::PopStyleColor();
            }
            ImGui::EndTable();
        }
    }
    ImGui::End();
}

void render_window3()
{
    static auto checked = false;
    static auto slider_value = 0;

    ImGui::SetNextWindowPos(ImVec2{700.0F, 300.0F});
    ImGui::SetNextWindowSize(ImVec2{400.0F, 150.0F});
    const auto window_flags =
        (ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoMove |
         ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize |
         ImGuiWindowFlags_NoTitleBar);
    if (ImGui::Begin("window###3", nullptr, window_flags))
    {
        ImGui::Text("Text1");
        ImGui::SameLine();
        ImGui::Text("Text2");

        ImGui::Separator();

        ImGui::Text("Text3");
        ImGui::SameLine();
        ImGui::Text("Text4");

        ImGui::Checkbox("Auto-resize", &checked);
        ImGui::SliderInt("Slider", &slider_value, 1, 10);
    }
    ImGui::End();
}

void render_window4()
{
    constexpr auto size1 = 1001U;
    constexpr auto size2 = 11U;

    auto xs1 = std::array<float, size1>{};
    auto ys1 = std::array<float, size1>{};
    auto ys2 = std::array<float, size2>{};
    auto xs2 = std::array<float, size2>{};

    for (int i = 0; i < size1; ++i)
    {
        xs1[i] = i * 0.001f;
        ys1[i] =
            0.5f + 0.5f * sinf(50 * (xs1[i] + (float)ImGui::GetTime() / 10));
    }
    for (int i = 0; i < size2; ++i)
    {
        xs2[i] = i * 0.1f;
        ys2[i] = xs2[i] * xs2[i];
    }

    ImGui::SetNextWindowPos(ImVec2{200.0F, 200.0F}, ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowSize(ImVec2{400.0F, 150.0F}, ImGuiCond_FirstUseEver);
    const auto window_flags =
        (ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoCollapse);
    if (ImGui::Begin("window###4", nullptr, window_flags))
    {
        ImPlot::CreateContext();
        if (ImPlot::BeginPlot("Line Plot"))
        {
            ImPlot::SetupAxes("x", "f(x)");
            ImPlot::PlotLine("sin(x)", xs1.data(), ys1.data(), size1);
            ImPlot::SetNextMarkerStyle(ImPlotMarker_Circle);
            ImPlot::PlotLine("x^2", xs2.data(), ys2.data(), size2);
            ImPlot::EndPlot();
        }
    }
    ImGui::End();
}

void render()
{
    // render_window1();
    // render_window2();
    // render_window3();
    // render_window4();

    render_exercise();
}
