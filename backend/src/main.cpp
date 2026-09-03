#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "../include/models.h"
#include "../include/recommendation.h"
#include "../include/schemes.h"

using namespace std;
using namespace AstitvaAI::Models;
using namespace AstitvaAI::Services;

// =============================================
// 🌟 AstitvaAI - C++ Backend Server
// Version: 1.0.0
// =============================================

int main() {
    cout << "========================================" << endl;
    cout << "🌟 AstitvaAI - C++ Backend Server v1.0" << endl;
    cout << "========================================" << endl;
    cout << "Server: http://localhost:8080" << endl;
    cout << "Status: Running" << endl;
    cout << "========================================" << endl;
    cout << endl;
    
    // =============================================
    // TEST: Create a sample user profile
    // =============================================
    
    cout << "📝 Testing Entrepreneur Profiling..." << endl;
    cout << endl;
    
    UserProfile profile;
    profile.name = "Rajesh Kumar";
    profile.age = 28;
    profile.location = "Chhindwara, Madhya Pradesh (rural)";
    profile.education = "Graduate";
    profile.skills = {"Farming", "Marketing"};
    profile.budget = 30000;
    profile.experience = "Less than 1 year";
    profile.language = "Hindi";
    
    cout << "✅ Profile Created:" << endl;
    cout << "   Name: " << profile.name << endl;
    cout << "   Age: " << profile.age << endl;
    cout << "   Location: " << profile.location << endl;
    cout << "   Budget: ₹" << profile.budget << endl;
    cout << endl;
    
    // =============================================
    // TEST: Get Business Recommendations
    // =============================================
    
    cout << "📋 Getting Business Recommendations..." << endl;
    cout << endl;
    
    auto recommendations = RecommendationService::getRecommendations(profile);
    
    cout << "💡 Top Business Recommendations:" << endl;
    cout << "----------------------------------------" << endl;
    for (size_t i = 0; i < recommendations.size(); ++i) {
        const auto& biz = recommendations[i];
        cout << i+1 << ". " << biz.icon << " " << biz.name << endl;
        cout << "   Category: " << biz.category << endl;
        cout << "   Investment: " << biz.investment_range << endl;
        cout << "   Profit: " << biz.profit_potential << endl;
        cout << "   Match Score: " << biz.match_score << "%" << endl;
        cout << "   Description: " << biz.description << endl;
        cout << endl;
    }
    
    // =============================================
    // TEST: Get Government Schemes
    // =============================================
    
    cout << "📋 Finding Government Schemes..." << endl;
    cout << endl;
    
    auto schemes = SchemeMatcher::getSchemes(profile);
    
    cout << "🏦 Eligible Government Schemes:" << endl;
    cout << "----------------------------------------" << endl;
    for (size_t i = 0; i < schemes.size(); ++i) {
        const auto& scheme = schemes[i];
        cout << i+1 << ". " << scheme.name << endl;
        cout << "   Category: " << scheme.category << endl;
        cout << "   Description: " << scheme.description << endl;
        cout << "   Benefits: " << scheme.benefits << endl;
        cout << "   Eligibility Score: " << scheme.eligibility_score << "%" << endl;
        cout << "   Apply: " << scheme.apply_link << endl;
        cout << endl;
    }
    
    cout << "========================================" << endl;
    cout << "✅ Server Demo Complete!" << endl;
    cout << "========================================" << endl;
    cout << endl;
    cout << "Press Ctrl+C to stop" << endl;
    
    // Keep server running
    while (true) {
        // In real implementation, this would handle HTTP requests
    }
    
    return 0;
}