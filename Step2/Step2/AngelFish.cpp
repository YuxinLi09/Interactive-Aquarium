/**
 * \file FishBeta.cpp
 *
 * \author Yuxin Li
 */

#include "pch.h"
#include "AngelFish.h"

using namespace std;
using namespace Gdiplus;

/// Fish filename 
const wstring AngelFishImageName = L"images/angelfish.png";

/** Constructor
 * \param aquarium The aquarium this is a member of
*/
CAngelFish::CAngelFish(CAquarium* aquarium) :
    CFish(aquarium, AngelFishImageName)
{
    MinSpeedX = 500;
    MinSpeedY = 100;
    MaxSpeedX = 800;
    MaxSpeedY = 300;
}

/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 * \return itemNode, the item that is going to be saved
 */
std::shared_ptr<xmlnode::CXmlNode>
CAngelFish::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    auto itemNode = CFish::XmlSave(node);
    itemNode->SetAttribute(L"type", L"angelfish");
    return itemNode;
}