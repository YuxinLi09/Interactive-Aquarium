/**
 * \file CatFish.h
 *
 * \author Yuxin Li
 *
 * Class the implements an catfish
 */

#pragma once

#ifndef CCATFISH_H
#define CCATFISH_H

#include "Fish.h"
#include <memory>
#include <string>

 /**
  * Implements an catfish
  */
class CCatFish : public CFish
 {
public:
    CCatFish(CAquarium* aquarium);

    /// Default constructor (disabled)
    CCatFish() = delete;

    /// Copy constructor (disabled)
    CCatFish(const CCatFish&) = delete;

    virtual std::shared_ptr<xmlnode::CXmlNode>
        XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

};

#endif