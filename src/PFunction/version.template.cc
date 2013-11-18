#ifndef VERSION_CC
#define VERSION_CC

#include<string>

namespace PRISMS
{
    std::string IntegrationTools_version_id()
    {
        return "VERSION_ID";
    };
    
    std::string IntegrationTools_commit_id()
    {
        return "COMMIT_ID";
    };
    
    std::string IntegrationTools_repo_url()
    {
        return "REPO_URL";
    };
}

#endif
