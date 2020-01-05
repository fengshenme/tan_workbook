import Vue from 'vue'
import Vuex from 'vuex'
import {getUser} from '@/utils/common'
Vue.use(Vuex)

// 每次刚进入网站，肯定会调用 main.js 在刚调用的时候，先从浏览器中，把数据读出来，放到 store 中
let token = getUser().token
let mobile = getUser().mobile
// 根状态对象,每个Vuex实例只是一个状态树
const state = {
  token: token,
  mobile: mobile
}
// 操作state的方法
const mutations = {
  increment (state,token) {
    state.token = token
  },
  ismobile(state,mobile){
    state.mobile = mobile
  }
}
//提交
const actions = {
  increment: ({ commit }) => commit('increment'),
  ismobile: ({ commit }) => commit('ismobile'),
}
// 属性计算
const getters = {
  token: state => state.token !== undefined ? true : false ,
  ismobile: state => state.mobile === undefined ? true :  false,
}

// Vuex实例是通过组合状态、变化、动作、和getter.
export default new Vuex.Store({
  state,
  getters,
  actions,
  mutations
})