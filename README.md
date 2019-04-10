# design_pattern_game
设计模式游戏应用
1.	针对唯一玩家人物设定，战斗、装备、技能等均需要频繁操作玩家人物的需求，选择使用单例模式。	
2.	针对不同角色具有相同的属性和方法需求，选择使用模板方法模式。
3.	针对不同装备具有相同的属性种类（攻击、血量、防御等），不同的属性实现，且装备需要经常创建以满足叠加的需求，选择使用工厂方法模式。
4.	针对玩家应有选择战斗时所使用的技能和随时切换技能的需求，选择使用策略模式。
5.	针对玩家探险过程中每次都会遇到新的陌生人物，小怪或者待解救者，这两种人物拥有相同的内部状态（对玩家生命值造成影响的方法）和不同的外部状态（伤害玩家或补给玩家），并且频繁的找怪操作，需支持大量细粒度的对象，选择使用享元模式。
6.  备忘录模式、观察者模式、装饰者模式
![Image text](https://github.com/mengfanli/design_pattern_game/blob/master/win32_helloword/uml.jpg)
