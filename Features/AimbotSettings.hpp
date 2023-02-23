#pragma once
#include "../imgui/imgui.h"

struct AimbotSettings
{
private:
    bool _enabled;
    bool _rage;
    float _verticalPower;
    float _horizontalPower;
    float _speed;
    float _maxAngleChangePerTick;
    float _rangeInMeters;
    int _hitbox;

public:
    AimbotSettings() : _enabled(false), _rage(false), _verticalPower(1.0f), _horizontalPower(1.0f), _speed(5.0f), _maxAngleChangePerTick(0.25f), _rangeInMeters(250.0f), _hitbox(2) {}
    
    AimbotSettings(bool enabled, bool rage, float verticalPower, float horizontalPower, float speed, float maxAngleChangePerTick, float rangeInMeters, int hitbox)
    {
        _enabled = enabled;
        _verticalPower = verticalPower;
        _horizontalPower = horizontalPower;
        _speed = speed;
        _maxAngleChangePerTick = maxAngleChangePerTick;
        _rangeInMeters = rangeInMeters;
        _hitbox = hitbox;
        _rage = rage;
    }

    bool isEnabled() const {
        return _enabled;
    }

    bool isRage() const {
        return _rage;
    }

    float getVerticalPower() const {
        return _verticalPower;
    }

    float getHorizontalPower() const {
        return _horizontalPower;
    }

    float getSpeed() const {
        return _speed;
    }

    float getMaxAngleChangePerTick() const {
        return _maxAngleChangePerTick;
    }

    float getRangeInMeters() const {
        return _rangeInMeters;
    }

    int getHitbox() const {
        return _hitbox;
    }

    void render()  {
        if(ImGui::BeginTabItem("Aimbot Settings")) {

            ImGui::Checkbox("Enabled", &_enabled);
            ImGui::Checkbox("Rage", &_rage);

            ImGui::SliderFloat("Vertical Power", &_verticalPower, 0.0f, 1.0f);
            ImGui::SameLine();
            ImGui::PushItemWidth(100); 
            ImGui::InputFloat("", &_verticalPower, 0.01f, 0.1f);
            ImGui::PopItemWidth(); 

            ImGui::SliderFloat("Horizontal Power", &_horizontalPower, 0.0f, 1.0f);
            ImGui::SameLine();
            ImGui::PushItemWidth(100); 
            ImGui::InputFloat("", &_horizontalPower, 0.01f, 0.1f);
            ImGui::PopItemWidth(); 

            ImGui::SliderFloat("Speed", &_speed, 0.0f, 100.0f);
            ImGui::SameLine();
            ImGui::PushItemWidth(100); 
            ImGui::InputFloat("", &_speed, 0.01f, 0.1f);
            ImGui::PopItemWidth(); 

            ImGui::SliderFloat("Max Angle Change Per Tick", &_maxAngleChangePerTick, 0.0f, 50.0f);
            ImGui::SameLine();
            ImGui::PushItemWidth(100); 
            ImGui::InputFloat("", &_maxAngleChangePerTick, 0.5f, 2.5f);
            ImGui::PopItemWidth(); 

            ImGui::SliderFloat("Range In Meters", &_rangeInMeters, 0.0f, 1000.0f);
            ImGui::SameLine();
            ImGui::PushItemWidth(100); 
            ImGui::InputFloat("", &_rangeInMeters, 1.0f, 10.0f);
            ImGui::PopItemWidth(); 

            ImGui::SliderInt("Hitbox", &_hitbox, 0, 5);
            ImGui::SameLine();
            ImGui::PushItemWidth(100); 
            ImGui::InputInt("", &_hitbox, 0.01f, 0.1f);
            ImGui::PopItemWidth(); 

            ImGui::EndTabItem();
        }
    }
};