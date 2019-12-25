import axios from 'axios'


/**
 * 定义只读的常量的httpUrl
 */
// export const httpUrl = 'http://47.94.241.234:9066/'
export const httpUrl = 'http://127.0.0.1:9066/'



/**
 * 封装的请求配置,var定义方便通过vuex修改
 */
export const request = axios.create({
    baseURL: httpUrl, // api的base_url 
    timeout: 300000, // 请求超时时间
  }) 
