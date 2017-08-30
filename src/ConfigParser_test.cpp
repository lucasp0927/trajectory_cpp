#include "ConfigParser.h"
namespace configparser
{
TEST(ConfigParserTest, functionTest_node_exist)
{
  char arg1[] = "./main";
  char arg2[] = "-C";
  char arg3[] = "red_lattice.yml";
  char* argv[] = {arg1,arg2,arg3};
  ConfigParser cp(3, argv);
  YAML::Node node = YAML::Load("{name: Brewers, city: Milwaukee}");
  ASSERT_TRUE(cp.node_exist(node,"name"));
  ASSERT_TRUE(cp.node_exist(node,"city"));
  ASSERT_FALSE(cp.node_exist(node,"random"));
  ASSERT_TRUE(cp.is_field_node(cp.fields_config["field"]));
  ASSERT_FALSE(cp.is_field_node(cp.fields_config));
}
}
