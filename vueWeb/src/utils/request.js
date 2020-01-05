import axios from 'axios'
import {Toast} from 'mint-ui'
import store from '@/store'
import {getUser,removeUser} from '@/utils/common'


// export const httpUrl = 'http://47.94.241.234:9066/'
export const httpUrl = 'http://127.0.0.1:9066/'

/**
 * 封装的请求配置
 */
const service = axios.create({
    baseURL: httpUrl, // api的base_url 
    timeout: 300000, // 请求超时时间
  }) 
  // 请求拦截器
service.interceptors.request.use(
  config => {
    //在发送请求之前做点什么
    if (store.getters.token) {
      //让每个请求携带令牌
      config.headers['Authorization'] = 'Bearer ' + getUser().token
    }
    return config
  },
  error => {
    // 处理请求错误
    return Promise.reject(error)
  }
)

//响应拦截器
service.interceptors.response.use(
  /**
   * 如果您想获得http信息，如头信息或状态信息
   * 通过自定义代码确定请求状态,你也可以通过HTTP状态码来判断状态
   */
  response => {
    const res = response
    // 如果自定义代码不是20000，则判断为错误.
    if (res.status !== 200) {
      // 50008: Illegal token; 50012: Other clients logged in; 50014: Token expired;
      if (res.status === 206) {
          removeUser()//清除登陆用户信息
          store.commit('ismobile',undefined)
          store.commit('increment',undefined)
          Toast("请您重新登录")
      }
      return res // Promise.reject(new Error(res.data || 'Error'))
    } else {
      return res
    }
  },
  error => {
    if( error.toString().substr(-3,3) === 401){
      removeUser()//清除登陆用户信息
      store.commit('ismobile',undefined)
      store.commit('increment',undefined)
      Toast("请您重新登录")
    }
    return Promise.reject(error)
  }
)

export default service