import testDateTime
import testHermes
import testThoth
import testEngine

testEngine.startTest()
testHermes.main()
testThoth.main()
testDateTime.main()
testEngine.env.printResults()