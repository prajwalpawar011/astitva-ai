#pragma once

#include "models.h"
#include <vector>

namespace AstitvaAI {
    namespace Services {
        
        class SchemeMatcher {
        public:
            static std::vector<Models::GovernmentScheme> 
            getSchemes(const Models::UserProfile& profile);
        };
        
    } // namespace Services
} // namespace AstitvaAI