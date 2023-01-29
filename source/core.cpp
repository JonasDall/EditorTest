#include <fstream>
#include "core.hpp"

bool pgePlayer::OnUserCreate(){
    std::ifstream ifile{""};
}

bool pgePlayer::OnUserUpdate(float fElapsedTime)
{

}

bool pgePlayer::OnUserDestroy(){}

bool pgeEditor::OnUserCreate(){
    // m_sprite = std::make_unique<olc::Sprite>("../assets/Tile");
}

bool pgeEditor::OnUserUpdate(float fElapsedTime){
    if(GetKey(olc::Key::ESCAPE).bPressed) return 0;

    if(GetKey(olc::Key::LEFT).bPressed)
    {
        olc::vi2d temp_location = {(int)(GetMouseX()), (int)(GetMouseY())};
        m_sprites.push_back(std::make_unique<permSprite>(temp_location));
        {
            std::ofstream outf("../assets/sprites.bin", std::ios::binary);
            if(outf)
            {
                cereal::BinaryOutputArchive outb(outf);

                outb(m_sprites);
            }
        }
    }

    Clear(olc::GREY);
    for (int i{}; i < m_sprites.size(); ++i)
    {
        DrawSprite(m_sprites[i].get()->m_location, m_sprites[i].get());
    }
}
bool pgeEditor::OnUserDestroy(){}

permSprite::permSprite(olc::vi2d location) : Sprite("../assets/Tile"), m_location{location}{}