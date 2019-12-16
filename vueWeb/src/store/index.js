import Vue from 'vue'
import Vuex from 'vuex'

Vue.use(Vuex)

// root state object.
// each Vuex instance is just a single state tree.
// 每次刚进入 网站，肯定会 调用 main.js 在刚调用的时候，先从本地存储中，把 购物车的数据读出来，放到 store 中
const car = JSON.parse(localStorage.getItem('car') || '[]')

const state = {
  car: car
}

// 突变实际上是改变状态的操作。
// 每个突变处理程序都将整个状态树作为
// 第一个参数，然后是附加的有效负载参数。
// 突变必须是同步的，并且可以通过插件记录
// 用于调试
const mutations = {
  addToCar (state, goodsinfo) {
    // 点击加入购物车，把商品信息，保存到 store 中的 car 上
    // 分析：
    // 1. 如果购物车中，之前就已经有这个对应的商品了，那么，只需要更新数量
    // 2. 如果没有，则直接把 商品数据，push 到 car 中即可
    // 假设 在购物车中，没有找到对应的商品
    var flag = false
    state.car.some(item => {
      if (item.id === goodsinfo.id) {
        item.count += parseInt(goodsinfo.count)
        flag = true
        return true
      }
    })
    // 如果最终，循环完毕，得到的 flag 还是 false，则把商品数据直接 push 到 购物车中
    if (!flag) {
      state.car.push(goodsinfo)
    }
    // 当 更新 car 之后，把 car 数组，存储到 本地的 localStorage 中
    localStorage.setItem('car', JSON.stringify(state.car))
  },

  updateGoodsInfo (state, goodsinfo) {
    // 修改购物车中商品的数量值
    state.car.some(item => {
      if (item.id === goodsinfo.id) {
        item.count = parseInt(goodsinfo.count)
        return true
      }
    })
    // 当修改完商品的数量，把最新的购物车数据，保存到 本地存储中
    localStorage.setItem('car', JSON.stringify(state.car))
  },

  removeFormCar (state, id) {
    // 根据Id，从store 中的购物车中删除对应的那条商品数据
    state.car.some((item, i) => {
      if (item.id === id) {
        state.car.splice(i, 1)
        return true
      }
    })
    // 将删除完毕后的，最新的购物车数据，同步到 本地存储中
    localStorage.setItem('car', JSON.stringify(state.car))
  },

  updateGoodsSelected (state, info) {
    state.car.some(item => {
      if (item.id === info.id) {
        item.selected = info.selected
      }
    })
    // 把最新的 所有购物车商品的状态保存到 store 中去
    localStorage.setItem('car', JSON.stringify(state.car))
  }

}

const actions = {
  addToCar: ({ commit }) => commit('addToCar'),
  updateGoodsInfo: ({ commit }) => commit('updateGoodsInfo'),
  removeFormCar: ({ commit }) => commit('removeFormCar'),
  updateGoodsSelected: ({ commit }) => commit('updateGoodsSelected')
}

// getter函数
const getters = {
  getAllCount: state => {
    var ab = 0
    state.car.forEach(item => {
      ab += item.count
    })
    return ab
  },
  getGoodsCount: state => {
    const o = {}
    state.car.forEach(item => {
      o[item.id] = item.count
    })
    return o
  },
  getGoodsSelected (state) {
    const o = {}
    state.car.forEach(item => {
      o[item.id] = item.selected
    })
    return o
  },
  getGoodsCountAndAmount (state) {
    const o = {
      count: 0, // 勾选的数量
      amount: 0 // 勾选的总价
    }
    state.car.forEach(item => {
      if (item.selected) {
        o.count += item.count
        o.amount += item.price * item.count
      }
    })
    return o
  }
}

// Vuex实例是通过组合状态、突变、动作创建的，和getter。
export default new Vuex.Store({
  state,
  getters,
  actions,
  mutations
})
