package org.web.demo.service;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import org.web.demo.mapper.UserMapper;
import org.web.demo.pojo.User;

@Service
public class UserService {

    @Autowired
    private UserMapper userMapper;

    public User queryById(Long id) {
        return userMapper.selectByFiled("User", id.toString());

    }

    @Transactional
    public void deleteById(Long id) {
        this.userMapper.deleteByPrimaryKey("User", id);
    }
}