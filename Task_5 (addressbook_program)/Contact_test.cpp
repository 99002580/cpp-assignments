#include "Contact.h"
#include "Address.h"

#include <gtest/gtest.h>

namespace {

class AddressTest : public ::testing::Test {

protected:
  void SetUp()
  {
    samples.add_contact("gbg", "s", "9845012340", "9845012341");
    samples.add_contact("Grisha", "sa", "9845012342", "9845012343");
    samples.add_contact("Surabhi", "sb", "9845012344", "9845012345");
    samples.add_contact("raghu", "sc", "9845012346", "9845012347");
    samples.add_contact("trupthi", "sd", "9845012348", "9845012349");
    samples.add_contact("samantha", "se", "9845012350", "9845012351");
  }
  void TearDown() {}
  Address samples;
};

TEST_F(AddressTest, AddContactTest) {
  EXPECT_EQ(6, samples.count_all());
  samples.add_contact("manju", "hegde", "9845012352", "9845012353");
  EXPECT_EQ(7, samples.count_all());
}

TEST_F(AddressTest, CountTest) {             //Just After Setup
  EXPECT_EQ(6, samples.count_all());
}

TEST_F(AddressTest, FindContactByPrimaryNumber) {
  Contact *ptr = samples.find_contact_by_primary_number("9845012348");
  //EXPECT_NE(NULL, ptr);
  EXPECT_STREQ("trupthi", ptr->getfirst_name().c_str());
  EXPECT_STREQ("sd", ptr->getlast_name().c_str());
  EXPECT_STREQ("9845012349", ptr->getalternate_number().c_str());
}

TEST_F(AddressTest, FindContactByFirstName) {
  Contact *ptr = samples.find_contact_by_name("samantha");
  //EXPECT_NE(NULL, ptr);
  EXPECT_STREQ("se", ptr->getlast_name().c_str());
  EXPECT_STREQ("9845012350", ptr->getprimary_number().c_str());
  EXPECT_STREQ("9845012351", ptr->getalternate_number().c_str());
}

TEST_F(AddressTest, FindContactByLastName) {
  Contact *ptr = samples.find_contact_by_name("s");
  //EXPECT_NE(NULL, ptr);
  EXPECT_STREQ("gbg", ptr->getfirst_name().c_str());
  EXPECT_STREQ("9845012340", ptr->getprimary_number().c_str());
  EXPECT_STREQ("9845012341", ptr->getalternate_number().c_str());
}

TEST_F(AddressTest, UpdateContactByPrimaryNumber) {
  Contact *ptr = samples.update_contact("9845012340","manju", "hegde","9845012353");
  //EXPECT_NE(NULL, ptr);
  EXPECT_STREQ("manju", ptr->getfirst_name().c_str());
  EXPECT_STREQ("hegde", ptr->getlast_name().c_str());
  EXPECT_STREQ("9845012353", ptr->getalternate_number().c_str());
}

/*
TEST_F(BillingTest, FindByIdTestFalse) {
  CustomerBase *ptr = customers.findCustomerById(1011);
  EXPECT_EQ(NULL, ptr);
}
TEST_F(BillingTest, FindByPhoneTest) {
  CustomerBase *ptr = customers.findCustomerByPhone("9845012347");
  EXPECT_EQ(300, ptr->getBalance());
  EXPECT_STREQ("Richard", ptr->getCustomerName().c_str());
  EXPECT_EQ(1003, ptr->getCustomerId());
}
TEST_F(BillingTest, AverageTest) {
  double avg = customers.findAverageBalance();
  EXPECT_EQ(475.0, avg);
}
TEST_F(BillingTest, MaxTest) {
  double maxbal = customers.findMaxBalance();
  EXPECT_EQ(800.0, maxbal);
}
TEST_F(BillingTest, CountMinBalTest) {
  int count = customers.countByMinBalance(320);
  EXPECT_EQ(4, count);
}
TEST_F(BillingTest, RemoveCustomerTest) {
  customers.removeCustomer(1005);
  EXPECT_EQ(NULL, customers.findCustomerById(1005));
  EXPECT_EQ(5, customers.countAll());
}
*/

} // namespace
