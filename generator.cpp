#include "generator.h"

Generator::Generator()
{
    LoadPrefabs("prefabs7x7.txt", prefabs7x7);
    LoadPrefabs("prefabs9x9.txt", prefabs9x9);
    LoadPrefabs("prefabs11x11.txt", prefabs11x11);
}

Generator::~Generator()
{
    prefabs7x7.clear();
    prefabs9x9.clear();
    prefabs11x11.clear();

    generation.clear();
}


void Generator::LoadPrefabs(std::string filename,std::vector<int> &v)
{
    std::ifstream prefabFile;
    char read;

    prefabFile.open(filename);
    if(prefabFile.is_open())
    {
        while(prefabFile.get(read))
        {
            if(read != '\n')
                v.push_back(TranslateFileChar(read));
        }

        prefabFile.close();
    }
    else
    {
        std::cerr << filename << " not found." << std::endl;
        std::cin.get();
        exit(1);
    }
}

int Generator::TranslateFileChar(char c)
{
    switch(c)
    {
    case 'x':
        return GEN_SKY;
        break;
    case '.':
        return GEN_EMPTY;
        break;
    case '#':
        return GEN_WALL;
        break;
    case '=':
        return GEN_DOOR;
        break;
    case '+':
        return GEN_VARIABLE;
        break;
    case '|':
        return GEN_BARS;
        break;
    default:
        return GEN_SKY;
        break;
    }
}

void Generator::GenerateFloor(int genW, int genH, std::vector<int>&result)
{
    /// Accumulate rooms by placing a random prefab in the center of the generation field.
    /// Move prefab toward field edges in a straight line, scanning for unoccupied space.
    /// If no unoccupied space is found before reaching the edge, add one strike.
    /// After 100 strikes, end accumulation.

    // Minimum size
    if(genW < 24)
        genW = 24;
    if(genH < 24)
        genH = 24;

    // blank slate
    result.clear();
    generation.clear();
    for(int i = 0; i < genW*genH; i++)
        generation.push_back(GEN_SKY);


    int genCenterX = genW/2;
    int genCenterY = genH/2;

    for(int generationStrikes = 0; generationStrikes < 100;)
    {
        std::vector<int>prefabContent;
        std::vector<int>doorableElements; // of activePrefab.
        prefabContent.clear();
        doorableElements.clear();

        int prefabLength = ((rand()%3)*2) + 7; // 7, 9, 11.
        int prefabArea = prefabLength*prefabLength;
        int prefabIndex = rand()%10;   // 0-9
        int prefabRotation = rand()%4; // Rotation*90 degrees.
        int prefabXFlip = rand()%1;    // Flip prefab horizontally if == 1.
        int prefabYFlip = rand()%1;    // Flip prefab vertically if == 1;
        int prefabDoors = rand()%3;    // Number of doors to generate for this room.

        float searchX = genCenterX;    // Coords of prefab's top-left corner in the generation field.
        float searchY = genCenterY;
        float searchAngle = (rand()%360) * 3.14159 / 180;  // Random degrees, converted to radians.

        bool searchComplete = false;

        std::vector<int>nothing;
        std::vector<int>&prefabRef = nothing;

        if(prefabLength == 7)
            prefabRef = prefabs7x7;
        if(prefabLength == 9)
            prefabRef = prefabs9x9;
        else if(prefabLength == 11)
            prefabRef = prefabs11x11;

        prefabContent = std::vector<int>(prefabRef.begin() + prefabArea*prefabIndex,
                                         prefabRef.begin() + prefabArea*prefabIndex +prefabArea);



        if(prefabRotation > 0)
        {

        }

        if(prefabXFlip == 1)
        {

        }

        if(prefabYFlip == 1)
        {

        }

        while(!searchComplete) // Search X/ Y
        {
            bool searchOccupied = false;

            if(searchX >= 0
               && searchX+prefabLength < genW
               && searchY >= 0
               && searchY+prefabLength < genH) // Search is within bounds
            {
                // Scan search area in the generation field for occupied space (not sky)
                for(int y = 0; y < prefabLength; y++)
                {
                    for(int x = 0; x < prefabLength; x++)
                    {
                        if(generation[(searchY+y) * genW + (searchX+x)] != GEN_SKY)
                            searchOccupied = true;

                        if(searchOccupied)
                            break;
                    }
                    if(searchOccupied)
                        break;
                }

                // Copy prefab to generation field if search area is unnocupied.
                if(!searchOccupied)
                {
                    for(int y = 0; y < prefabLength; y++)
                    {
                        for(int x = 0; x < prefabLength; x++)
                        {
                            generation[(searchY+y)*genW +(searchX+x)] = prefabContent[(y*prefabLength)+x];
                        }
                    }
                    searchComplete = true;
                    // Successful search does not increment generationStrikes.
                }

                // Move searchX/Y in one step in a line, at an angle. Round to nearest integer.
                searchX += 1.01*cos(searchAngle);
                searchY += 1.01*sin(searchAngle);


            }
            else
            {
                searchComplete = true;
                generationStrikes++;
            }

        }

        // Reset search coords to generation field center.
        searchX = genW/2;
        searchY = genH/2;

    }
    for(int i = 0; i < genW*genH; i++)
    {
        result.push_back(generation[i]);
    }
}
