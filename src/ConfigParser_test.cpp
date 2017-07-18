#include "ConfigParser.h"

TEST(ConfigParserTest, functionTest_node_exist)
{
  ConfigParser cp;
  YAML::Node node = YAML::Load("{name: Brewers, city: Milwaukee}");
  ASSERT_TRUE(cp.node_exist(node,"name"));
  ASSERT_TRUE(cp.node_exist(node,"city"));
  ASSERT_FALSE(cp.node_exist(node,"random"));
}
