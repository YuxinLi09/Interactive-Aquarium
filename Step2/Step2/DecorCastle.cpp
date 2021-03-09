/**
 * \file FishBeta.cpp
 *
 * \author Yuxin Li
 */

#include "pch.h"
#include "DecorCastle.h"

using namespace std;
using namespace Gdiplus;

/// Fish filename 
const wstring CastleImageName = L"images/castle.png";

/** Constructor
 * \param aquarium The aquarium this is a member of
*/
CDecorCastle::CDecorCastle(CAquarium* aquarium) :
    CItem(aquarium, CastleImageName)
{
}

/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 * \return itemNode The node that is going to be saved
 */
std::shared_ptr<xmlnode::CXmlNode>
CDecorCastle::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    auto itemNode = CItem::XmlSave(node);
    itemNode->SetAttribute(L"type", L"castle");
    return itemNode;
}
