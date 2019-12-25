<template>
  <div id="app">
    Clicked: {{ $store.state.count }} times, 数 是 {{ evenOrOdd }}.
    <br>
    <button @click="increment">+</button>
    <hr>
    {{$store.state.count}}
    <hr>
      First name: <input type="text"  v-model="pojo.ia" name="fname"><br>
      Last name: <input type="text" v-model="pojo.ic" name="lname"><br>
      <button  @click="ac" > 提交</button>
      {{pojo}}
  </div>
</template>

<script>
import { mapGetters, mapActions } from 'vuex'

export default {
  data() {
    return {
      pojo:{ia:"aa",ic:"cc"},
      aatoken:this.$store.state.token
    }
  },
  computed: {
    ...mapGetters([
      'evenOrOdd',
    ]),
  },
  methods: {
    ...mapActions(['increment']),
    ac(){
      this.$store.commit('increment',this.pojo)
    }
  }
}
</script>

<style lang="scss" scoped>

</style>
