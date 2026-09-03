#include "../include/schemes.h"
#include <algorithm>

using namespace std;
using namespace AstitvaAI::Models;

namespace AstitvaAI {
    namespace Services {
        
        vector<GovernmentScheme> 
        SchemeMatcher::getSchemes(const UserProfile& profile) {
            
            // Sample government schemes
            vector<GovernmentScheme> allSchemes = {
                {
                    "PMEGP - Employment Generation Programme",
                    "Self-Employment",
                    "Financial assistance for setting up micro enterprises",
                    "18+ years, 8th pass, rural/urban areas",
                    "Subsidy up to 35% (50% for SC/ST/Women)",
                    "₹1 Lakh - ₹25 Lakh",
                    "MSME",
                    {"Aadhar", "Address Proof", "Caste Certificate", "Bank Account"},
                    "https://www.kviconline.gov.in/pmegp/",
                    0.0
                },
                {
                    "MUDRA Loan - Pradhan Mantri MUDRA Yojana",
                    "Finance",
                    "Business loans for micro and small enterprises",
                    "Any Indian citizen with business plan",
                    "Collateral-free loans up to ₹10 Lakhs",
                    "₹50,000 - ₹10 Lakh",
                    "Finance",
                    {"Aadhar", "PAN", "Business Plan", "Bank Account"},
                    "https://www.mudra.org.in/",
                    0.0
                },
                {
                    "Stand-Up India",
                    "SME Finance",
                    "Loans for SC/ST and Women entrepreneurs",
                    "SC/ST/Women, 18+ years, business experience",
                    "Loan for greenfield enterprises",
                    "₹10 Lakh - ₹1 Crore",
                    "Finance",
                    {"Caste Certificate", "Project Report", "Experience Certificate"},
                    "https://www.standupmitra.in/",
                    0.0
                },
                {
                    "PMFME - PM Formalisation of Micro Enterprises",
                    "MSME",
                    "Support for micro enterprises",
                    "Existing micro enterprises",
                    "Capital support up to ₹50,000",
                    "₹50,000",
                    "MSME",
                    {"Aadhar", "Business Registration", "Bank Account"},
                    "https://pmfme.gov.in/",
                    0.0
                },
                {
                    "National Small Industries Corporation (NSIC)",
                    "MSME",
                    "Support for small scale industries",
                    "Registered MSME",
                    "Marketing support, raw material assistance",
                    "Variable",
                    "MSME",
                    {"Aadhar", "PAN", "Business Registration"},
                    "https://www.nsic.co.in/",
                    0.0
                }
            };
            
            // Calculate eligibility scores
            for (auto& scheme : allSchemes) {
                double score = 0.0;
                
                // Age check
                if (profile.age >= 18) score += 30;
                
                // Education check
                if (!profile.education.empty()) {
                    if (profile.education.find("Graduate") != string::npos) score += 20;
                    else if (profile.education.find("High School") != string::npos) score += 15;
                    else if (profile.education.find("Primary") != string::npos) score += 10;
                    else score += 5;
                }
                
                // Location check (rural gets more points)
                if (profile.location.find("rural") != string::npos) score += 20;
                else if (profile.location.find("urban") != string::npos) score += 10;
                
                // Experience check
                if (profile.experience == "More than 5 years") score += 20;
                else if (profile.experience == "3-5 years") score += 15;
                else if (profile.experience == "1-3 years") score += 10;
                else if (profile.experience == "Less than 1 year") score += 5;
                
                scheme.eligibility_score = min(score, 100.0);
            }
            
            // Filter eligible schemes (score >= 50)
            vector<GovernmentScheme> eligible;
            for (const auto& scheme : allSchemes) {
                if (scheme.eligibility_score >= 50) {
                    eligible.push_back(scheme);
                }
            }
            
            // Sort by eligibility score (highest first)
            sort(eligible.begin(), eligible.end(),
                [](const GovernmentScheme& a, const GovernmentScheme& b) {
                    return a.eligibility_score > b.eligibility_score;
                });
            
            return eligible;
        }
        
    } // namespace Services
} // namespace AstitvaAI