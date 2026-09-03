#include "../include/recommendation.h"
#include <algorithm>

using namespace std;
using namespace AstitvaAI::Models;

namespace AstitvaAI {
    namespace Services {
        
        vector<BusinessRecommendation> 
        RecommendationService::getRecommendations(const UserProfile& profile) {
            
            // Sample business database
            vector<BusinessRecommendation> allBusinesses = {
                {
                    "Organic Vegetable Farming",
                    "Agriculture",
                    "₹25,000 - ₹50,000",
                    {"Farming", "Marketing"},
                    "High",
                    "₹15,000 - ₹25,000/month",
                    "Medium",
                    "🌱",
                    0.0,
                    "Grow organic vegetables for local markets"
                },
                {
                    "Home-based Catering",
                    "Food",
                    "₹15,000 - ₹30,000",
                    {"Cooking", "Planning"},
                    "Very High",
                    "₹20,000 - ₹35,000/month",
                    "Low",
                    "🍳",
                    0.0,
                    "Provide home-cooked meals for events"
                },
                {
                    "Tailoring & Boutique",
                    "Textile",
                    "₹20,000 - ₹40,000",
                    {"Tailoring", "Creativity"},
                    "High",
                    "₹15,000 - ₹30,000/month",
                    "Medium",
                    "👗",
                    0.0,
                    "Design and stitch clothes for local customers"
                },
                {
                    "Poultry Farming",
                    "Agriculture",
                    "₹30,000 - ₹60,000",
                    {"Farming", "Animal Care"},
                    "High",
                    "₹20,000 - ₹30,000/month",
                    "Medium",
                    "🐔",
                    0.0,
                    "Start a poultry farm for eggs and meat"
                },
                {
                    "Handicraft Business",
                    "Artisan",
                    "₹10,000 - ₹25,000",
                    {"Crafts", "Creativity"},
                    "Medium",
                    "₹10,000 - ₹20,000/month",
                    "Low",
                    "🎨",
                    0.0,
                    "Create and sell handmade crafts"
                },
                {
                    "Mobile Repair Shop",
                    "Technology",
                    "₹15,000 - ₹35,000",
                    {"Electronics", "Repair"},
                    "High",
                    "₹15,000 - ₹25,000/month",
                    "Low",
                    "📱",
                    0.0,
                    "Repair mobile phones and sell accessories"
                },
                {
                    "Beauty Parlour",
                    "Services",
                    "₹20,000 - ₹50,000",
                    {"Beauty", "Makeup"},
                    "High",
                    "₹20,000 - ₹40,000/month",
                    "Low",
                    "💄",
                    0.0,
                    "Provide beauty and grooming services"
                }
            };
            
            // Calculate match scores
            vector<BusinessRecommendation> matched;
            
            for (auto& biz : allBusinesses) {
                double score = 0.0;
                
                // Budget check
                if (profile.budget >= 20000) score += 30;
                else if (profile.budget >= 15000) score += 20;
                else if (profile.budget >= 10000) score += 10;
                
                // Skills check
                for (const string& skill : profile.skills) {
                    for (const string& reqSkill : biz.required_skills) {
                        if (skill == reqSkill) {
                            score += 20;
                        }
                    }
                }
                
                // Location bonus
                if (!profile.location.empty()) score += 10;
                
                // Experience bonus
                if (profile.experience != "None") score += 10;
                
                biz.match_score = min(score, 100.0);
                
                if (biz.match_score >= 30) {
                    matched.push_back(biz);
                }
            }
            
            // Sort by match score (highest first)
            sort(matched.begin(), matched.end(),
                [](const BusinessRecommendation& a, const BusinessRecommendation& b) {
                    return a.match_score > b.match_score;
                });
            
            // Return top 5
            if (matched.size() > 5) {
                matched.resize(5);
            }
            
            return matched;
        }
        
    } // namespace Services
} // namespace AstitvaAI