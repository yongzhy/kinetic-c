#ifndef _SYSTEM_TEST_FIXTURE
#define _SYSTEM_TEST_FIXTURE

#include "kinetic_types.h"

typedef struct _SystemTestInstance
{
    bool testIgnored;
    bool nonBlocking;
    KineticOperation operation;
    KineticPDU request;
    KineticPDU response;
    KineticMessage requestMsg;
    uint8_t* value;
    int64_t valueLength;
} SystemTestInstance;

typedef struct _SystemTestFixture
{
    char host[HOST_NAME_MAX];
    int port;
    int64_t clusterVersion;
    int64_t identity;
    int64_t expectedSequence;
    char hmacKey[KINETIC_HMAC_MAX_LEN];
    uint8_t data[PDU_VALUE_MAX_LEN];
    bool connected;
    KineticConnection connection;
    SystemTestInstance instance;
} SystemTestFixture;

void SystemTestSetup(SystemTestFixture* fixture);
void SystemTestTearDown(SystemTestFixture* fixture);
void SystemTestSuiteTearDown(SystemTestFixture* fixture);

#define SYSTEM_TEST_SUITE_TEARDOWN(_fixture) \
void test_Suite_TearDown(void) \
{ \
    TEST_ASSERT_NOT_NULL_MESSAGE((_fixture), "System test fixture passed to 'SYSTEM_TEST_SUITE_TEARDOWN' is NULL!"); \
    if ((_fixture)->connected) \
        KineticClient_Disconnect(&(_fixture)->connection); \
    (_fixture)->connected = false; \
    (_fixture)->instance.testIgnored = true; \
}

#endif // _SYSTEM_TEST_FIXTURE
