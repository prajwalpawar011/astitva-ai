#pragma once

#include <string>
#include <vector>

using namespace std;

namespace AstitvaAI {
    namespace Models {
        
        // User Profile (Step 1)
        struct UserProfile {
            string name;
            int age;
            string location;
            string education;
            vector<string> skills;
            double budget;
            string experience;
            string language;  // Hindi, Marathi, English
        };
        
        // Business Recommendation (Step 2)
        struct BusinessRecommendation {
            string name;
            string category;
            string investment_range;
            vector<string> required_skills;
            string demand_level;
            string profit_potential;
            string risk_level;
            string icon;
            double match_score;
            string description;
        };
        
        // Government Scheme (Step 4)
        struct GovernmentScheme {
            string name;
            string category;
            string description;
            string eligibility;
            string benefits;
            string loan_amount;
            string sector;
            vector<string> documents;
            string apply_link;
            double eligibility_score;
        };
        
        // Document Checklist (Step 5)
        struct DocumentChecklist {
            vector<string> required;
            vector<string> submitted;
            vector<string> pending;
        };
        
        // Business Roadmap (Step 6)
        struct BusinessRoadmap {
            vector<string> steps;
            vector<bool> completed;
            string estimated_timeframe;
            string current_step;
        };
        
    } // namespace Models
} // namespace AstitvaAI