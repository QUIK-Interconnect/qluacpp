#include "api.hpp"

int qlua::api::AllocTable() {
  const char api_name[] = "AllocTable";
  typedef std::tuple<int> return_type;
  auto result = lua_.pcall<return_type>(api_name, std::tuple<>());
  return std::get<0>(result);
}

bool qlua::api::AddColumn(const int& t_id, const int& iCode, const char* name, const bool& is_default, const int& par_type, const int& width) {
  char api_name[] = "AddColumn";
  typedef std::tuple<int> return_type;
  auto params = std::make_tuple(t_id, iCode, name, is_default, par_type, width);
  auto result = lua_.pcall<return_type>(api_name, params);
  return std::get<0>(result) == 1;  
}

int qlua::api::InsertRow(const int& t_id, const int& key) {
  const char api_name[] = "InsertRow";
  typedef std::tuple<int> return_type;
  auto params = std::make_tuple(t_id, key);
  auto result = lua_.pcall<return_type>(api_name, params);
  return std::get<0>(result);  
}


bool qlua::api::SetCell(const int& t_id, const int& key, const int& code, const char* text) {
  const char api_name[] = "SetCell";
  typedef std::tuple<bool> return_type;
  auto params = std::make_tuple(t_id, key, code, text);
  auto result = lua_.pcall<return_type>(api_name, params);
  return std::get<0>(result) == 1;  
}

bool qlua::api::SetCell(const int& t_id, const int& key, const int& code, const char* text, const double& value) {
  const char api_name[] = "SetCell";
  typedef std::tuple<bool> return_type;
  auto params = std::make_tuple(t_id, key, code, text, value);
  auto result = lua_.pcall<return_type>(api_name, params);
  return std::get<0>(result) == 1;  
}

bool qlua::api::SetWindowCaption(const int& t_id, const char* str) {
  const char api_name[] = "SetWindowCaption";
  typedef std::tuple<bool> return_type;
  auto params = std::make_tuple(t_id, str);
  auto result = lua_.pcall<return_type>(api_name, params);
  return std::get<0>(result);  
}


bool qlua::api::CreateWindow(const int t_id) {
  const char api_name[] = "CreateWindow";
  typedef std::tuple<int> return_type;
  auto params = std::make_tuple(t_id);
  auto result = lua_.pcall<return_type>(api_name, params);
  return std::get<0>(result) == 1;  
}
