import request from '@/utils/request'
const groupName = 'user'
const apiName = 'user'

 // 登录
export function Login (user) {
  return request({
    url: `/${apiName}/login/`,
    method: 'post',
    data: user
  })
}
/**
 * 注册 pojo->user
 * @param {*} pojo 
 * @param {*} code 
 */
export function Register (pojo, code) {
  return request({
    url: `/${groupName}/register/${code}`,
    method: 'post',
    data: pojo
  })
}

/**
 * 发送短信
 * @param {*} mobile 
 */
export function Sendsms (mobile) {
  return request({
    url: `/${groupName}/sendsms/${mobile}`,
    method: 'get'
  })
}
/**
 * 注销登录
 */
export function Logout () {
  return request({
    url: `/${groupName}/logout`,
    method: 'delete'
  })
}

export function findUserAll () {
  return request({
    url: `/user/findall`,
    method: 'put'
  })
}
/**
 * 登录状态监测
 * @param {*} mobile 
 */
export function LoginStatus(mobile){
    return request({
      url: `/user/loginstatus/${mobile}`,
      method: 'get'
    })
}
