package org.web.demo.mapper;

import org.apache.ibatis.annotations.Mapper;
import org.web.demo.pojo.User;

@Mapper
public interface UserMapper extends BaseMapper<User> {
}