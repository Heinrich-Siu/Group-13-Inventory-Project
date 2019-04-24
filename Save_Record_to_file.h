//
//  Save_Record_to_file.hpp
//  1340 Working batch
//
//  Created by Heinrich Siu on 20/4/2019.
//  Copyright © 2019 Heinrich Siu. All rights reserved.
//

#ifndef Save_Record_to_file_h
#define Save_Record_to_file_h

#include <stdio.h>
#include "inventorysys.h"

void saveRecordToFile(commodity *shopPtr, int numberOfCommodity, std::string oldFileName);
void fileToMake(std::string &name, bool change);






#endif /* Save_Record_to_file_hpp */
