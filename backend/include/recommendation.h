#pragma once

#include "models.h"
#include <vector>

namespace AstitvaAI {
    namespace Services {
        
        class RecommendationService {
        public:
            static std::vector<Models::BusinessRecommendation> 
            getRecommendations(const Models::UserProfile& profile);
        };
        
    } // namespace Services
} // namespace AstitvaAI