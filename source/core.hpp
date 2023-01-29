#include "../libs/pge/olcPGE.hpp"
#include "../libs/cereal/cereal.hpp"
#include "../libs/cereal/archives/binary.hpp"
#include "../libs/cereal/types/vector.hpp"
#include "../libs/cereal/types/memory.hpp"
#include "../libs/cereal/access.hpp"

class permSprite;

class pgePlayer : public olc::PixelGameEngine
{
    std::vector<std::unique_ptr<permSprite>> m_sprites;
    // std::unique_ptr<permSprite> m_sprite;

    bool OnUserCreate();
    bool OnUserUpdate(float fElapsedTime);
    bool OnUserDestroy();
};

class pgeEditor : public olc::PixelGameEngine
{
    std::vector<std::unique_ptr<permSprite>> m_sprites;
    // std::unique_ptr<permSprite> m_sprite;

    bool OnUserCreate();
    bool OnUserUpdate(float fElapsedTime);
    bool OnUserDestroy();
};

class permSprite : public olc::Sprite
{
private:
    friend cereal::access;

    template<class Archive>
    void serialize(Archive & ar){
        ar(pColData, width, height, modeSample, loader, m_location);
    }

public:
    olc::vi2d m_location{};
    permSprite(olc::vi2d location);
};